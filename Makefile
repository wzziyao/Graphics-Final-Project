game:
	g++ -std=c++11 src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/Vector2D.cpp src/Collision.cpp -o play -I include -L lib -l SDL2-2.0.0 -l SDL2_image