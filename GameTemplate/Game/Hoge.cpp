#include "stdafx.h"
#include "Hoge.h"


Hoge::Hoge()
{
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"Hello World");
}


Hoge::~Hoge()
{
}
