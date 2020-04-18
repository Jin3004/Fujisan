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



//------(�֐��E���\�b�h�̒�`)

void Core::update() {
	frame++;
}

Pointer<Game> Start::update() {
	return nullptr;
}

void Start::draw()const {
	Rect(0, 0, 400, 400).draw(Palette::Blue);
}

//------



//------(�O���[�o���I�u�W�F�N�g)

Core core;

//------