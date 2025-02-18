// 类装饰器

function classDecorator(constructor: Function) {
  console.log(`Class: ${constructor.name} is being decorated`);
}

@classDecorator
class MyClass1 {
  name = 'Alice';
}

const myClass1 = new MyClass1(); // Class: MyClass1 is being decorated

// 方法装饰器

function log(tareget: any, propertykey: string, descriptor: PropertyDescriptor) {
  const originalMethod = descriptor.value;

  descriptor.value = function(...args: any[]) {
    console.log('The method args are: ', args.join(', '));
    const result = originalMethod.apply(this, args);
    console.log('The return value is: ', result);
    return result;
  }
}

class MyClass2 {
  @log
  greet(name: string) {
    return `Hello ${name}`;
  }
}

// 属性装饰器
function readonly(target: any, key: string) {
  Object.defineProperty(target, key, { writable: false });
}

class MyClass3 {
  @readonly
  name = 'Alice';
}

const myClass3 = new MyClass3();
// myClass3.name = 'Bob'; // 报错

// 参数装饰器
function logParameter(target: any, key: string, index: number) {
  console.log(`The parameter in position ${index} at ${key} has been decorated`);
}

class MyClass4 {
  greet(@logParameter name: string) {
    return `Hello ${name}`;
  }
}