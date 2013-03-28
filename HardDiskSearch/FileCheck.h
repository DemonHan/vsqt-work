#pragma once
#include <string>
#include <map>
struct FileStruct{
	std::string strFilePath;
	std::string strFileName;
	unsigned int FileSize;
};
class CFileCheck
{
protected:
	std::multimap< std::string, FileStruct > m_FileMap;
public:
	CFileCheck(void);
	CFileCheck( const CFileCheck &File );
	CFileCheck& operator=( const CFileCheck & );
	virtual void HardDiskResearch( std::string pStrPath )=0;
	virtual ~CFileCheck(void);
	void GetFileMap( std::map< std::string, FileStruct > &fileMap );
};

