#pragma once
class Hoge : public IGameObject
{
public:
	Hoge();
	~Hoge();
	prefab::CFontRender* m_fontRender = nullptr;
};

