import pygame
import random

# Initialize Pygame
pygame.init()

# Set up display dimensions
WIDTH, HEIGHT = 800, 600
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Ball Return Game")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# Player properties
PLAYER_WIDTH, PLAYER_HEIGHT = 100, 20
PLAYER_VELOCITY = 10

# Ball properties
BALL_RADIUS = 20
BALL_VELOCITY = 3

# Fonts
font = pygame.font.Font(None, 36)

# Player class
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((PLAYER_WIDTH, PLAYER_HEIGHT))
        self.image.fill(RED)
        self.rect = self.image.get_rect()
        self.rect.centerx = WIDTH // 2
        self.rect.bottom = HEIGHT - 10

    def update(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and self.rect.left > 0:
            self.rect.x -= PLAYER_VELOCITY
        if keys[pygame.K_RIGHT] and self.rect.right < WIDTH:
            self.rect.x += PLAYER_VELOCITY

# Ball class
class Ball(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((BALL_RADIUS * 2, BALL_RADIUS * 2), pygame.SRCALPHA)
        pygame.draw.circle(self.image, BLACK, (BALL_RADIUS, BALL_RADIUS), BALL_RADIUS)
        self.rect = self.image.get_rect()
        self.rect.centerx = random.randint(50, WIDTH - 50)
        self.rect.centery = random.randint(50, HEIGHT // 2)
        self.velocity = [random.choice([-1, 1]) * BALL_VELOCITY, BALL_VELOCITY]

    def update(self):
        self.rect.x += self.velocity[0]
        self.rect.y += self.velocity[1]

        if self.rect.left <= 0 or self.rect.right >= WIDTH:
            self.velocity[0] = -self.velocity[0]

        if self.rect.top <= 0:
            self.velocity[1] = -self.velocity[1]

# Sprite groups
all_sprites = pygame.sprite.Group()
balls = pygame.sprite.Group()

player = Player()
all_sprites.add(player)

# Game loop
running = True
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    all_sprites.update()

    # Ball logic
    if len(balls) < 1:
        ball = Ball()
        all_sprites.add(ball)
        balls.add(ball)

    for ball in balls:
        if pygame.sprite.collide_rect(ball, player):
            ball.velocity[1] = -ball.velocity[1]

    # Draw everything
    WIN.fill(WHITE)
    all_sprites.draw(WIN)

    # Update display
    pygame.display.flip()
    clock.tick(60)

pygame.quit()