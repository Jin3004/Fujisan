#include <Siv3D.hpp>
#include <memory>
#include <string>
#include <unordered_map>
#include <type_traits>



//------(�G�C���A�X�錾)

template<typename T>
using Pointer = std::shared_ptr<T>;

//------


//------(�R���Z�v�g)

template<typename T>
concept ResourceClass = std::is_same_v<T, s3d::Texture> || std::is_same_v<T, s3d::Audio>;

//------



//------(�O���錾)

class Core;

template<typename T>
class ResourceManager;

class Game;

class Start;

//------