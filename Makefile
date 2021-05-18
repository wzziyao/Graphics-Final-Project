game:
	g++ main.cpp Game.cpp TextureManager.cpp GameObject.cpp Map.cpp Vector2D.cpp -o play -I include -L lib -l SDL2-2.0.0 -l SDL2_image