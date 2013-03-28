#include "WinFileCheck.h"
#include <afx.h>
#define my_Debug
CWinFileCheck::CWinFileCheck(void)
{
}


CWinFileCheck::~CWinFileCheck(void)
{
}

void CWinFileCheck::HardDiskResearch( std::string StrPath )
{
	// 将要检索的文件路径转换为cstring类型
	CString cstrCheckPath = StrPath.c_str();
	cstrCheckPath += _T("\\*.*");

	// 记录查找文件或路径时是否成功
	bool bFinding(false);

	//MFC类CFileFind执行本地文件查找
	CFileFind fileFinder;
	try {
		bFinding = fileFinder.FindFile( cstrCheckPath );
	}
	catch (CException* e) {
		TCHAR szReason[256];
		e->GetErrorMessage( szReason, 256 );
#ifdef my_Debug
		printf( "%s\n", szReason );
#endif
	}
	while ( bFinding ) {
		bFinding = fileFinder.FindNextFile();
#ifdef my_Debug
		printf( "%s", (LPCTSTR)fileFinder.GetFileName() );
#endif
		if ( fileFinder.IsDots() ){
			continue;
		}
		else if ( fileFinder.IsSystem() ){
			continue;
		}
		else if ( fileFinder.IsDirectory() ){
// 			CString cstrNextPath = cstrCheckPath;
// 			cstrNextPath += fileFinder.GetFileName();
			// 对新的目录进行递归获取文件名
			std::string strNextPath = CT2A(fileFinder.GetFilePath().GetBuffer() );
			this->HardDiskResearch( strNextPath );
		}
		else{
			// 将相应的文件信息放入文件目录
			FileStruct fileData;
			fileData.FileSize = fileFinder.GetLength();
			fileData.strFileName = CT2A( fileFinder.GetFileName().GetBuffer() );
			fileData.strFilePath = CT2A( fileFinder.GetFilePath().GetBuffer() );
			m_FileMap.insert( make_pair( fileData.strFileName, fileData ) );
		}
	}
}
