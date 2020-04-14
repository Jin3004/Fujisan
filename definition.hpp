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

extern Core core;

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

void update(Pointer<Game>& ptr) {
	while (core.exit_state) {
		core.exit_state = System::Update();
		core.update();
		auto res = ptr->update();
		if (res != nullptr)ptr = res;
	}
}

void draw(Pointer<Game>& ptr) {
	while (core.exit_state) {
		ptr->draw();
	}
}

void Core::update() {
	frame++;
}

Pointer<Game> Start::update() {
	return nullptr;
}

void Start::draw()const {
	Rect(0, 0, 400, 400).draw(Palette::Blue);
}

//------(�֐��E���\�b�h�̒�`)