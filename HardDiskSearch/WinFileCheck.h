#pragma once
#include "filecheck.h"
class CWinFileCheck :
	public CFileCheck
{
public:
	CWinFileCheck(void);
	virtual ~CWinFileCheck(void);
	virtual void HardDiskResearch( std::string pStrPath );
};

