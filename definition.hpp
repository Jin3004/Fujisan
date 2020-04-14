#pragma once
#include "declaration.hpp"



//------(�N���X�̒�`)

class Core {
public:
	//System::Update()�̖߂�l
	bool exit_state = true;
	//���t���[����
	uint64_t frame = 0;
	//���O�B�A�v���I�����Ƀe�L�X�g�ɏ�������
	std::string log = ""s;

	void update();

};

class Game {
public:
	//�������֐��BGame�̃C���X�^���X���ύX�����ۂɎ��s����
	virtual void initialize() {}
	//���t���[�����s�����
	virtual Pointer<Game> update() { return nullptr; }
	//���t���[�����s�����(update()�Ƃ͕ʃX���b�h��)
	virtual void draw()const {}
};

class Start : public Game {
public:
	Pointer<Game> update()override;
	void draw()const override;
};

//------