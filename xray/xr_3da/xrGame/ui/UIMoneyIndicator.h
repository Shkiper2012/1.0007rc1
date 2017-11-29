#pragma once

#include "UIWindow.h"
#include "UIStatic.h"

class CUIXml;
class CUIColorAnimatorWrapper;
class CUIGameLog;

class CUIMoneyIndicator: public CUIWindow {
public:
	CUIMoneyIndicator();
	virtual ~CUIMoneyIndicator();
	virtual void Update();
			void InitFromXML(CUIXml& xml_doc);
			void SetMoneyAmount(LPCSTR money);
			void SetMoneyChange(LPCSTR money);

protected:
	CUIStatic	m_back;
	CUIStatic	m_money_amount;
	CUIStatic	m_money_change;

	CUIColorAnimatorWrapper* m_pAnimChange;
	CUIGameLog*				 m_pBonusMoney;
};

