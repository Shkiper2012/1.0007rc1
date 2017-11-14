#include "stdafx.h"
#include "UIMessageBox.h"
#include "UIXmlInit.h"
#include "UI3tButton.h"
#include "UIEditBox.h"
#include "../string_table.h"

CUIMessageBox::CUIMessageBox()
{
	m_UIButtonYesOk		= NULL;
	m_UIButtonNo		= NULL;
	m_UIButtonCancel	= NULL;
	m_UIStaticPicture	= NULL;
	m_UIStaticText		= NULL;
}

CUIMessageBox::~CUIMessageBox()
{
	Clear();
}

#define BUTTON_UP_OFFSET 75
#define BUTTON_WIDTH 140

void CUIMessageBox::Clear(){
	xr_delete(m_UIButtonYesOk);
	xr_delete(m_UIButtonNo);
	xr_delete(m_UIButtonCancel);
	xr_delete(m_UIStaticPicture);
	xr_delete(m_UIStaticText);
}

bool CUIMessageBox::OnMouse(float x, float y, EUIMessages mouse_action)
{
	return inherited::OnMouse(x, y, mouse_action);
}

void CUIMessageBox::Init	(LPCSTR box_template)
{
	Clear();
	CUIXml uiXml;
	bool xml_result = uiXml.Init	(CONFIG_PATH, UI_PATH, "message_box.xml");
	R_ASSERT3						(xml_result, "xml file not found", "message_box.xml");

	CUIXmlInit xml_init;

	string512 str;

	strconcat								(sizeof(str),str,box_template,":picture");
	m_UIStaticPicture						= xr_new<CUIStatic>();AttachChild(m_UIStaticPicture);
	xml_init.InitStatic						(uiXml, str, 0, m_UIStaticPicture);

	strconcat								(sizeof(str),str,box_template,":message_text");
	if (uiXml.NavigateToNode(str,0)){
        m_UIStaticText							= xr_new<CUIStatic>();AttachChild(m_UIStaticText);
        xml_init.InitStatic						(uiXml, str, 0, m_UIStaticText);
	}

	strcpy		(str,box_template);
	xml_init.InitStatic						(uiXml, str, 0, this);

	LPCSTR _type							= uiXml.ReadAttrib(str,0,"type",NULL);
	R_ASSERT								(_type);
	
	m_eMessageBoxStyle	= MESSAGEBOX_OK;
	if(0==stricmp(_type,"ok")){
		m_eMessageBoxStyle	= MESSAGEBOX_OK;
	}else
	if(0==stricmp(_type,"yes_no")){
		m_eMessageBoxStyle	= MESSAGEBOX_YES_NO;
	}else
	if(0==stricmp(_type,"yes_no_cancel")){
		m_eMessageBoxStyle	= MESSAGEBOX_YES_NO_CANCEL;
	}else
	if(0==stricmp(_type,"quit_windows")){
		m_eMessageBoxStyle	= MESSAGEBOX_QUIT_WINDOWS;
	}else 
	if(0==stricmp(_type,"quit_game")){
		m_eMessageBoxStyle	= MESSAGEBOX_QUIT_GAME;
	}else 
		if(0==stricmp(_type,"info")){
			m_eMessageBoxStyle	= MESSAGEBOX_INFO;
		};
	

	switch (m_eMessageBoxStyle){

		case MESSAGEBOX_OK:{
			strconcat							(sizeof(str),str,box_template,":button_ok");
			m_UIButtonYesOk						= xr_new<CUI3tButton>();
			AttachChild							(m_UIButtonYesOk);
			xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonYesOk);
		}break;
		case MESSAGEBOX_INFO:
		{
		}break;

		case MESSAGEBOX_QUIT_WINDOWS:
		case MESSAGEBOX_QUIT_GAME:
		case MESSAGEBOX_YES_NO:
			{
				strconcat							(sizeof(str),str,box_template,":button_yes");
				m_UIButtonYesOk						= xr_new<CUI3tButton>();
				AttachChild							(m_UIButtonYesOk);
				xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonYesOk);

				strconcat							(sizeof(str),str,box_template,":button_no");
				m_UIButtonNo						= xr_new<CUI3tButton>();
				AttachChild							(m_UIButtonNo);
				xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonNo);
			}break;

		case MESSAGEBOX_YES_NO_CANCEL:{
			strconcat							(sizeof(str),str,box_template,":button_yes");
			m_UIButtonYesOk						= xr_new<CUI3tButton>();
			AttachChild							(m_UIButtonYesOk);
			xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonYesOk);

			strconcat							(sizeof(str),str,box_template,":button_no");
			m_UIButtonNo						= xr_new<CUI3tButton>();
			AttachChild							(m_UIButtonNo);
			xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonNo);

			strconcat							(sizeof(str),str,box_template,":button_cancel");
			m_UIButtonCancel					= xr_new<CUI3tButton>();
			AttachChild							(m_UIButtonCancel);
			xml_init.Init3tButton				(uiXml, str, 0, m_UIButtonCancel);
		}break;
	};
}


void CUIMessageBox::SendMessage(CUIWindow *pWnd, s16 msg, void *pData)
{
	if(msg == BUTTON_CLICKED){
		switch(m_eMessageBoxStyle)
		{
		case MESSAGEBOX_OK:
			if(pWnd == m_UIButtonYesOk)
					GetMessageTarget()->SendMessage(this, MESSAGE_BOX_OK_CLICKED);
			break;
		case MESSAGEBOX_YES_NO:
		case MESSAGEBOX_QUIT_GAME:
		case MESSAGEBOX_QUIT_WINDOWS:
			if(pWnd == m_UIButtonYesOk)
			{
				if (MESSAGEBOX_QUIT_GAME == m_eMessageBoxStyle)
                    GetMessageTarget()->SendMessage(this, MESSAGE_BOX_QUIT_GAME_CLICKED);
				else if (MESSAGEBOX_QUIT_WINDOWS == m_eMessageBoxStyle)
					GetMessageTarget()->SendMessage(this, MESSAGE_BOX_QUIT_WIN_CLICKED);
				else
					GetMessageTarget()->SendMessage(this, MESSAGE_BOX_YES_CLICKED);
			}
			else if(pWnd == m_UIButtonNo)
			{
				GetMessageTarget()->SendMessage(this, MESSAGE_BOX_NO_CLICKED);
			}
			break;
		case MESSAGEBOX_YES_NO_CANCEL:
			if(pWnd == m_UIButtonYesOk)
			{
				GetMessageTarget()->SendMessage(this, MESSAGE_BOX_YES_CLICKED);
			}
			else if(pWnd == m_UIButtonNo)
			{
				GetMessageTarget()->SendMessage(this, MESSAGE_BOX_NO_CLICKED);
			}
			else if(pWnd == m_UIButtonCancel)
			{
				GetMessageTarget()->SendMessage(this, MESSAGE_BOX_CANCEL_CLICKED);
			}
			break;
		};
	};
	inherited::SendMessage(pWnd, msg, pData);
}

void CUIMessageBox::SetText(LPCSTR str)
{
	m_UIStaticText->SetText(*(CStringTable().translate(str)));
}

LPCSTR CUIMessageBox::GetText()
{
	return m_UIStaticText->GetText();
}

