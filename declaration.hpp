#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <string>
#include <thread>



//------(�G�C���A�X�錾)

template<typename T>
using Pointer = std::shared_ptr<T>;

//------



//------(�O���錾)

class Core;

template<typename T>
class ResourceManager;

class Game;

class Start;

//------