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

template<typename T>
class ResourceManager {
private:
public:
	std::string base_path = "sources/"s;
	std::unordered_map<std::string, Pointer<T>> resource_data; //(�t�@�C����, ���\�[�X�I�u�W�F�N�g�̃|�C���^)�̏W��

	ResourceManager() {
		static_assert(std::is_same_v<T, s3d::Texture> || std::is_same_v<T, s3d::Audio>, "Template arg is not s3d::Texture, not");
	}

	//operator[]
	T operator[](std::string filename) {

		if (resource_data.find(filename) == resource_data.end()) {
			resource_data[filename] = std::make_shared<T>(Unicode::Widen(base_path + filename));
		}

		return *(resource_data[filename]);

	}

};

struct Label {
	int32_t x, y;
	std::string str;
	void draw(Font& font, s3d::Color color) {
		font(Unicode::Widen(str)).drawAt(x, y, color);
	}
};

struct Buttons {
	std::vector<Label> labels;
	std::vector<bool> is_clicked; //�ǂ��̃{�^�����N���b�N���ꂽ��
	std::vector<bool> is_active;
	Font& font; //�`��p�̃t�H���g
	int32_t focused_index = 0;
	const size_t size;

	Buttons(size_t size, Font& font) : labels(size), is_clicked(size, false), is_active(size), font(font), size(size) {}
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
	int32_t cnt = 0;

	Pointer<Game> update()override;
	void draw()const override;

};

//------



//------(�O���[�o���I�u�W�F�N�g)

Core core;
ResourceManager<Texture> textures;

//------



//------(�֐��E���\�b�h�̒�`)

void Core::update() {
	exit_state = System::Update();
	frame++;
}

Pointer<Game> Start::update() {
	return nullptr;
}

void Start::draw()const {

}

void Buttons::update() {

	//------(is_clicked�̏�����(�O�t���[���̏�Ԃ��c���Ă���̂�))

	for (size_t i = 0; i < size; ++i)is_clicked[i] = false;

	//

	//------(focus_index�̍X�V)

	if (DownInput.down()) {
		focused_index = (focused_index + 1) % size;
	}
	if (UpInput.down()) {
		focused_index--;
		if (focused_index == -1)focused_index = size - 1;
	}

	//------

	//------(�L�[�̊Ď�)

	if (EnterInput.down())is_clicked[focused_index] = true;

	//------

	//------(�{�^���̕`��)

	for (size_t i = 0; i < size; ++i) {
		auto& label = labels[i];
		
		//------(�g�̕`��)

		Rect rect{ label.x - BUTTON_WIDTH / 2, label.y - BUTTON_HEIGHT - 2, BUTTON_WIDTH, BUTTON_HEIGHT };

		{
			Transformer2D t{ Mat3x2::Rotate(2_deg, rect.pos) };
			rect.stretched(-2, 1, 1, -4).drawShadow(Vec2(0, 0), 12, 0, ColorF(0.0, 0.4));
		}

		if (i == focused_index)rect.draw(HSV(0, 0.46, 1.0));
		else

		//------

	}

	//------

}

//------