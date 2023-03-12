import pygame
import random

# Initialize Pygame
pygame.init()

# Set the game window dimensions
WINDOW_WIDTH = 500
WINDOW_HEIGHT = 500

# Set the snake block dimensions
BLOCK_SIZE = 10

# Set the game clock
clock = pygame.time.Clock()

# Set the game window
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Snake")

# Define the Snake class
class Snake:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.velocity_x = BLOCK_SIZE
        self.velocity_y = 0
        self.length = 1
        self.body = [(self.x, self.y)]

    def move(self):
        # Move the snake
        self.x += self.velocity_x
        self.y += self.velocity_y

        # Update the snake's body
        self.body.append((self.x, self.y))
        if len(self.body) > self.length:
            self.body.pop(0)

    def draw(self):
        # Draw the snake's body
        for block in self.body:
            pygame.draw.rect(window, (0, 255, 0), (block[0], block[1], BLOCK_SIZE, BLOCK_SIZE))

    def eat(self, food):
        # Check if the snake has eaten the food
        if self.x == food.x and self.y == food.y:
            self.length += 1
            return True
        return False

    def collide(self):
        # Check if the snake has collided with the game window boundaries
        if self.x < 0 or self.x >= WINDOW_WIDTH or self.y < 0 or self.y >= WINDOW_HEIGHT:
            return True
        # Check if the snake has collided with itself
        for block in self.body[:-1]:
            if block == (self.x, self.y):
                return True
        return False

# Define the Food class
class Food:
    def __init__(self):
        self.x = random.randint(0, WINDOW_WIDTH-BLOCK_SIZE)
        self.y = random.randint(0, WINDOW_HEIGHT-BLOCK_SIZE)

    def draw(self):
        # Draw the food
        pygame.draw.rect(window, (255, 0, 0), (self.x, self.y, BLOCK_SIZE, BLOCK_SIZE))

# Initialize the snake and food
snake = Snake(WINDOW_WIDTH/2, WINDOW_HEIGHT/2)
food = Food()

# Set the game loop
game_over = False
while not game_over:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                snake.velocity_x = 0
                snake.velocity_y = -BLOCK_SIZE
            elif event.key == pygame.K_DOWN:
                snake.velocity_x = 0
                snake.velocity_y = BLOCK_SIZE
            elif event.key == pygame.K_LEFT:
                snake.velocity_x = -BLOCK_SIZE
                snake.velocity_y = 0
            elif event.key == pygame.K_RIGHT:
                snake.velocity_x = BLOCK_SIZE
                snake.velocity_y = 0

    # Move the snake
    snake.move()

    # Check if the snake has eaten the food
    if snake.eat(food):
        food = Food()

    # Check if the snake has collided with anything
    if snake.collide():
        game_over = True

    # Clear the window and draw the objects
    window.fill((0, 0))
