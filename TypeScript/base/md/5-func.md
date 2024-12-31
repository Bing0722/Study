# 函数

## 定义函数

```js
// 函数声明
function square(x) {
  return x * x;
}
// 函数表达式
const square = function (x) {
  return x * x;
};
```

## 函数提升

JavaScript 解释器会将整个函数声明提升到当前作用域的顶部
函数提升仅适用于函数声明，而不适用于函数表达式

## 嵌套函数和闭包

你可以在一个函数里面嵌套另外一个函数
它自身也形成了一个闭包（closure）

```js
// 外部函数定义了一个名为“name”的变量
const pet = function (name) {
  const getName = function () {
    // 内部函数可以访问外部函数的“name”变量
    return name;
  };
  return getName; // 返回内部函数，从而将其暴露给外部作用域
};
const myPet = pet("Vivie");

console.log(myPet()); // "Vivie"
```

## 使用 arguments 对象

函数的实际参数会被保存在一个类似数组的 arguments 对象中。在函数内，你可以按如下方式找出传入的参数：

```js
arguments[i];

function myConcat(separator) {
  let result = ""; // 初始化列表
  // 迭代 arguments
  for (let i = 1; i < arguments.length; i++) {
    result += arguments[i] + separator;
  }
  return result;
}
```

## 函数参数

### 默认参数

在 JavaScript 中，函数参数的默认值是 undefined

```js
function multiply(a, b = 1) {
  return a * b;
}

console.log(multiply(5)); // 5
```

### 剩余参数

剩余参数语法允许将不确定数量的参数表示为数组

```js
function multiply(multiplier, ...theArgs) {
  return theArgs.map((x) => multiplier * x);
}

const arr = multiply(2, 1, 2, 3);
console.log(arr); // [2, 4, 6]
```

### 箭头参数

相比函数表达式具有较短的语法且没有它自己的 this、arguments、super 和 new.target。箭头函数总是匿名的

```js
const a = ["Hydrogen", "Helium", "Lithium", "Beryllium"];

const a2 = a.map(function (s) {
  return s.length;
});

console.log(a2); // [8, 6, 7, 9]

const a3 = a.map((s) => s.length);

console.log(a3); // [8, 6, 7, 9]
```
