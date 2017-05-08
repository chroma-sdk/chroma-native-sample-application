
#include "stdafx.h"
#include "FrameController.h"

DWORD g_dwCurrentTickCount = 0;

// CFrameController
CFrameController::CFrameController():
    m_FramesPerSec(-1),
    m_OneFrame(0)
{

}

CFrameController::CFrameController(LONG FramePerSec):
    m_FramesPerSec(FramePerSec),
    m_OneFrame(1000.0/m_FramesPerSec)
{
}

CFrameController::~CFrameController()
{

}

void CFrameController::Begin()
{
    g_dwCurrentTickCount = GetTickCount();
}

void CFrameController::End()
{
    static DWORD dwSleep = 0;
    static DWORD dwDiff = 0;

    dwDiff = GetTickCount() - g_dwCurrentTickCount;
    dwSleep = DWORD(m_OneFrame - (DOUBLE)dwDiff);

    if (dwDiff < m_OneFrame)
    {
        Sleep(dwSleep);
    }
}

void CFrameController::SetRate(LONG FramePerSec)
{
    m_FramesPerSec = FramePerSec;
    m_OneFrame = 1000.0 / m_FramesPerSec;
}

LONG CFrameController::GetRate(void)
{
    return m_FramesPerSec;
}
