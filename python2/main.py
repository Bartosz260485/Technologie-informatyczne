from abc import ABC, abstractmethod
import math


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * (self.radius ** 2)

    def perimeter(self):
        return 2 * math.pi * self.radius


class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)


class Square(Shape):
    def __init__(self, width):
        self.width = width

    def area(self):
        return self.width * self.width

    def perimeter(self):
        return 4 * self.width


class Triangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return (self.width * self.height) / 2

    def perimeter(self):
        przeciwprostokatna = math.sqrt(self.width ** 2 + self.height ** 2)
        return self.width + self.height + przeciwprostokatna


class Trapez(Shape):
    def __init__(self, width, width2, height):
        self.width = width
        self.width2 = width2
        self.height = height

    def area(self):
        return ((self.width + self.width2) * self.height) / 2

    def perimeter(self):
        ramie = math.sqrt(self.height ** 2 + ((self.width - self.width2) / 2) ** 2)
        return self.width + self.width2 + 2 * ramie


if __name__ == '__main__':
    circle = Circle(5)
    rectangle = Rectangle(width=4, height=6)
    square = Square(5)
    triangle = Triangle(width=5, height=4)
    trapez = Trapez(width=5, width2=4, height=3)

    print("Circle Area:", circle.area())
    print("Circle Perimeter:", circle.perimeter())
    print()

    print("Rectangle Area:", rectangle.area())
    print("Rectangle Perimeter:", rectangle.perimeter())
    print()

    print("Square Area:", square.area())
    print("Square Perimeter:", square.perimeter())
    print()

    print("Triangle Area:", triangle.area())
    print("Triangle Perimeter:", triangle.perimeter())
    print()

    print("Trapezoidal Area:", trapez.area())
    print("Trapezoidal Perimeter:", trapez.perimeter())