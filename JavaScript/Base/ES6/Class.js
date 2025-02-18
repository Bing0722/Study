// Class

// 定义一个类
class Person {
  // 构造函数 用于初始化实例
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  // 实例方法
  greet() {
    console.log(
      `Hello, my name is ${this.name} and I am ${this.age} years old.`
    );
  }
}

// 实例化
let person = new Person("Tom", 20);
person.greet(); // Hello, my name is Tom and I am 20 years old.

// 继承
// 使用 extends 关键字继承另一个类
class Student extends Person {
  // 构造函数 用于初始化实例
  constructor(name, age, grade) {
    // 调用父类的构造函数 super() 方法
    super(name, age);
    this.grade = grade;
  }

  // 实例方法
  study() {
    console.log(`${this.name} is studying in grade ${this.grade}.`);
  }
}

// 实例化
let student = new Student("Jerry", 18, 12);
student.greet(); // Hello, my name is Jerry and I am 18 years old.
student.study(); // Jerry is studying in grade 12.

// 静态方法
// 使用 static 关键字定义静态方法
// 只能通过类名调用，不能通过实例调用
class Math {
  static add(a, b) {
    return a + b;
  }
}

console.log(Math.add(1, 2)); // 3

// getter 和 setter
// 使用 get 和 set 关键字定义 getter 和 setter
class Rectangle {
  constructor(width, height) {
    this.width = width;
    this.height = height;
  }

  // Getter
  get area() {
    return this.width * this.height;
  }

  // Setter
  set area(value) {
    this.width = value / this.height;
  }
}

const rectangle = new Rectangle(10, 5);
console.log(rectangle.area); // 输出: 50

rectangle.area = 100; // 设置面积
console.log(rectangle.width); // 输出: 20
