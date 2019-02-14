#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Hoge.h"

Game::Game()
{
	NewGO< Hoge>(0);
}


Game::~Game()
{
}
bool Game::Start()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	
	return true;
}

void Game::Update()
{
	//Y�������5�x���N�H�[�^�j�I�����쐬����B
	CQuaternion qAddRot;
	qAddRot.SetRotationDeg(
		{ 0.0f, 1.0f, 0.0f },
		5.0f
	);
	//��]����Z���ĉ��Z����B
	m_rotation *= qAddRot;
	m_skinModelRender->SetRotation(m_rotation);
	
	//�A�i���O�X�e�B�b�N�̓��͂œ������B
	m_position.x += Pad(0).GetLStickXF() * -2.0f;

	m_skinModelRender->SetPosition(m_position);
}