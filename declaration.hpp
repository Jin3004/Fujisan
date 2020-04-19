#include <Siv3D.hpp>
#include <memory>
#include <string>
#include <unordered_map>
#include <type_traits>
#include <initializer_list>
#include <algorithm>



//------(�G�C���A�X�錾)

template<typename T>
using Pointer = std::shared_ptr<T>;

//------


//------(�萔�錾�Ȃ�)

extern auto UpInput	   = KeyUp;
extern auto DownInput  = KeyDown;
extern auto RightInput = KeyRight;
extern auto LeftInput  = KeyLeft;
extern auto EnterInput = KeyEnter;

extern constexpr size_t BUTTON_WIDTH  = 256;
extern constexpr size_t BUTTON_HEIGHT = 96;

//------


//------(�O���錾)

class Core;

template<typename T>
class ResourceManager;

class Game;

class Start;

//------



//------(���[�e�B���e�B�֌W)

//------