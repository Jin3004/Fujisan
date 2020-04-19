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
	frame++;
}

Pointer<Game> Start::update() {
	return nullptr;
}

void Start::draw()const {
}

//------