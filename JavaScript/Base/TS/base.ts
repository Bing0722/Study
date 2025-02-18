// 类型注解
let a: string; // ts 官方推荐使用小写
let b: number;
let c: boolean;
let d: 'hello'; // 字面量类型

a = 'Hello';
b = 1;
c = true;

console.log(a, b, c);

function count(x: number, y: number): number {
  return x + y;
}

let result = count(1, 2);
console.log(result);

// 常用类型
// any 任意类型 一般不使用 赋值给其他类型不会报错 污染全局
let e: any; // 任意类型
e = 1;
e = '1';
e = true;

// unknown 类型安全的any类型
// 
let f: unknown;
f = 1;
f = '1';
f = true;

let x: string;
// x = f; // 报错
// 第一种方式 
if (typeof f === 'string') {
  x = f;
}

// 第二种方式 类型断言
x = f as string;

// 第三种方式
x = <string>f;

// never 永远不会返回结果的类型
function error(message: string): never {
  throw new Error(message);
}

// void 没有返回值的类型
function fn(): void {
  console.log('hello');
  // 隐式返回undefined
}

// object 
let obj: object; // 存储非原始类型
let Obj: Object; // 存储原始类型
obj = {};
obj = function() {};
obj = [];

// a = 1; // 报错
// a = true; // 报错

// Obj // 存储除了 null undefined 之外的所有类型

let person: {
  name: string
  age?: number // 可选属性
  [key: string]: any // 任意属性
}

person = {
  name: 'zhangsan',
  age: 18,
  gender: '男'
}

let arr: number[]; // 数组类型
arr = [1, 2, 3];

// tuple 元组类型
let tuple: [string, number, boolean];
tuple = ['hello', 1, true];

let tuple2: [string, ...number[] ];
tuple2 = ['hello', 1, 2, 3, 4, 5];

// 枚举类型
enum Direction {
  up,
  down,
  left,
  right
}
// 枚举类型通常使用 const

// type 类型别名
type Status = number | string;

function printStatus(status: Status) {
  console.log(status);
}
printStatus(404);
printStatus('404');


