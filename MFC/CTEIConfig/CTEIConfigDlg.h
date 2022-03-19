
// CTEIConfigDlg.h : ͷ�ļ�
//

#pragma once
#include"../../../System/Setting/Readini/INIManager.hpp"

// CCTEIConfigDlg �Ի���
class CCTEIConfigDlg : public CDialogEx
{
// ����
public:
	CCTEIConfigDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTEICONFIG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CEdit mCTEIEdit;
	CEdit mVEREdit;
	CButton mELINK;
	iniManager mConfig;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
};
