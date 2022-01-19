#include "Header.h"

void Interface::start() {
	utils.intf = this;
	game.intf = this;
	enemy.intf = this;
	
	printf("NEW GAME STARTED\n\n");

	utils.catch_errors();

	init();

	utils.load_bmps();

	settings.print();

	printf("\n");

	event_loop();

	utils.destroy_window(0);
}

void Interface::init() {
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, settings.SCREEN_WIDTH, settings.SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, settings.WINDOW_TITLE);

	screen = SDL_CreateRGBSurface(0, settings.SCREEN_WIDTH, settings.SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	colors.init(screen);
	draw.init(screen, this);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, settings.SCREEN_WIDTH, settings.SCREEN_HEIGHT);

	SDL_ShowCursor(SDL_DISABLE);

	charset = SDL_LoadBMP("./img/cs8x8.bmp");
	if (charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		exit(1);
	}
	SDL_SetColorKey(charset, true, 0x000000);

	game.place();
}

void Interface::event_loop() {
	t1 = SDL_GetTicks();

	frames = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	fpsTimer = 0;
	collisionTimer = 0;

	while (!quit) {
		t2 = SDL_GetTicks();

		// here t2-t1 is the time in milliseconds since
		// the last screen was drawn
		// delta is the same time in seconds
		delta = ((double)t2 - t1) * 0.001;
		t1 = t2;

		worldTime += delta;

		fpsTimer += delta;

		collisionTimer += delta;

		SDL_FillRect(screen, NULL, colors.black);

		if (frames * 2 >= settings.MAX_FPS) {
			fps = frames * 2;
			frames = 0;
		}

		enemy.shoot();

		draw.start(charset);

		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);

		if (player.collider.collision(enemy.collider)) {
			restart();
		}

		if (collisionTimer > 3) {
			int start = bullets.start % Q_SIZE;
			int end = bullets.end % Q_SIZE;
			for (int i = start; i <= end; i++) {
				Bullet b = bullets.Q[i];
				if (player.collider.collision(b.collider)) {
					player.health -= b.damage;
					collisionTimer = 0;

					switch (b.direction) {
					case 0:
						bullets.Q[i].position.x -= 1000;
						break;
					case 1:
						bullets.Q[i].position.x += 1000;
						break;
					case 2:
						bullets.Q[i].position.y -= 1000;
						break;
					case 3:
						bullets.Q[i].position.y += 1000;
						break;
					}
				}

				if (player.health <= 0) {
					player.health = 100;
					restart();
				}
			}
		}

		if (player.collider.collision(enemy.collider)) {
			restart();
		}

		event_handler();
		
		frames++;
	}
}

void Interface::event_handler() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			key_down();
			break;
		case SDL_KEYUP:
			key_up();
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		}
	}
}

void Interface::key_down() {
	Vector velocity = {-2, -2};

	switch (event.key.keysym.sym) {
	case SDLK_ESCAPE:
		quit = 1;
		break;
	case SDLK_n:
		restart();
		break;
	case SDLK_a:
		velocity.x = -1;
		player.set_direction(false);
		break;
	case SDLK_d:
		velocity.x = 1;
		player.set_direction(true);
		break;
	case SDLK_w:
		velocity.y = -1;
		break;
	case SDLK_s:
		velocity.y = 1;
		break;
	}

	player.update_velocity(velocity);
	bool move = player.move();
	if (player.in_center() && !move && (velocity.x != 0 && velocity.y != 0)) {
		bg.update_velocity(utils.reverse_velocity(velocity));
		enemy.update_velocity(utils.reverse_velocity(velocity));
		if (!bg.move()) {
			deb printf("Player cannot move\n");
		}
		else {
			enemy.move();
		}
	}
}

void Interface::key_up() {
	Vector velocity = {-2, -2};

	switch (event.key.keysym.sym) {
	case SDLK_a:
	case SDLK_d:
		velocity.x = 0;
		break;
	case SDLK_w:
	case SDLK_s:
		velocity.y = 0;
		break;
	}

	bg.update_velocity(velocity);
	enemy.update_velocity(velocity);
	player.update_velocity(velocity);
}

void Interface::restart() {
	utils.destroy_window(-1);
	start();
	exit(0);
}