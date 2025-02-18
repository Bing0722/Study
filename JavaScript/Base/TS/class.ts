/**
 * 类修饰符
 * 1. public 公有的 默认修饰符
 * 2. private 私有的 只能在当前类中访问
 * 3. protected 受保护的 只能在当前类和子类中访问
 * 4. readonly 只读的
 */
class Person {
  // public name: string;
  // age: number;
  // constructor(name: string, age: number) {
  //     this.name = name;
  //     this.age = age;
  // }
  // 简化写法
  constructor(
    public name: string,
    protected readonly age: number,
    private idCard: string
  ) {}
  
  protected getAge() {
      return this.age;
  }
  
  private getIdCard() {
      return this.idCard;
  }

  public sayHello() {
      return `Hello, my name is ${this.name}`;
  }
}

const person3 = new Person('zhangsan', 18, '123456');

class Student extends Person {
  greade: string;
  constructor(name: string, age: number, grade: string) {
      super(name, age, '123456');
  this.greade = grade;
  }
  override sayHello() {
      return `Hello, my name is ${this.name}, I am a student`;
  }
}

const student = new Student('lisi', 19, 'grade one');

// 抽象类
abstract class Animal {
  // 构造函数
  constructor(public name: string) {}
  // 抽象方法
  abstract makeSound(): void;
  // 具体方法
  move(): void {
      console.log('roaming the earth...');
  }
}

class Dog extends Animal {
  constructor(name: string, public age: number) {
      super(name);
  }
  makeSound() {
      console.log('wangwangwang');
  }
}

// interface 接口
interface PersonInterface {
  name: string;
  age: number;
  sayHello(n: number): string;
}

class Person2 implements PersonInterface {
  constructor(public name: string, public age: number) {
  }
  sayHello(n: number) {
      return `Hello, my name is ${this.name}, I am ${n}`;
  }
}

const person4 = new Person2('zhangsan', 18);

// 泛型

function logData<T>(data: T){
  console.log(data);
}

logData<string>('hello');
logData<number>(123);

