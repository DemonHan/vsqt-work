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
	// ��Ҫ�������ļ�·��ת��Ϊcstring����
	CString cstrCheckPath = StrPath.c_str();
	cstrCheckPath += _T("\\*.*");

	// ��¼�����ļ���·��ʱ�Ƿ�ɹ�
	bool bFinding(false);

	//MFC��CFileFindִ�б����ļ�����
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
			// ���µ�Ŀ¼���еݹ��ȡ�ļ���
			std::string strNextPath = CT2A(fileFinder.GetFilePath().GetBuffer() );
			this->HardDiskResearch( strNextPath );
		}
		else{
			// ����Ӧ���ļ���Ϣ�����ļ�Ŀ¼
			FileStruct fileData;
			fileData.FileSize = fileFinder.GetLength();
			fileData.strFileName = CT2A( fileFinder.GetFileName().GetBuffer() );
			fileData.strFilePath = CT2A( fileFinder.GetFilePath().GetBuffer() );
			m_FileMap.insert( make_pair( fileData.strFileName, fileData ) );
		}
	}
}
