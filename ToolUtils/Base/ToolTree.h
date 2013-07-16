#ifndef _TOOL_TREE_H_
#define _TOOL_TREE_H_

#define _CRT_SECURE_NO_WARNINGS

#include <afx.h>
#include <afxwin.h>
#include <afxcmn.h>
#include <afxdtctl.h>
#include "OptionTree.h"
#include "ToolDef.h"
#include "ToolApp.h"

BEGIN_NS_AC

class COptionTreeItemStaticEx : public COptionTreeItemStatic
{
public:
	virtual void OnSelect()
	{
		ToolTree* pTree = (ToolTree*)m_otOption;
		int nCurrSelID = atoi(GetInfoText().GetBuffer());
		pTree->SelectID(nCurrSelID);
	}
};

// 下面的多继承必须将CTabCtrl放前面，否则BEGIN_MESSAGE_MAP时
// 会报警，运行时会出现指针转换导致出错

class ToolTree : public COptionTree, public Module<ToolApp>
{
public:
	ToolTree(ToolApp* app);
	virtual ~ToolTree();
public:
	BOOL Create(RECT rcRect, CWnd* pWnd, UINT nID);
public:
	int Create();
public:
	void SelectID(int id);
private:
	int m_nLastSelID;
};

END_NS_AC

#endif//_TOOL_TREE_H_