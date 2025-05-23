# 数据结构和类型

最新的 ECMAScript 标准定义了 8 种数据类型

- 七种基本数据类型：
  - Boolean: true 和 false
  - null: 一个表明 null 值的特殊关键字
  - undefined: 一个表明 undefined 值的特殊关键字
  - Number: 一个整数或浮点数，例如 42 或 3.14159
  - BigInt: 一个任意精度的整数
  - String: 一个字符序列，例如 "Howdy"
  - Symbol: 用于对象属性的唯一标识
- 以及 Object

## 数据类型的转换

JavaScript是一门动态类型语言，这意味着你在声明变量时可以不必指定该变量的数据类型

```js
let anser = 42;
anser = "Hello";
```

## 数字和`+`运算符

在使用 `+` 运算符的表达式中涉及数字和字符串，JavaScript 会把数字转换成字符串

```js
x = "nubmer" + 1 + 2; // "number12"
y = 1 + 2 + "number"; // "3number"
z = "12" + 3 + 4; // "1234"
```

在使用其他运算符时，JavaScript 不会把数字转换成字符串

```js
"37" - 7; // 30
"37" * 7; // 259
```

## 字符串转化为数字

有一些方法可以将内存中表示一个数字的字符串转换为数字

- parseInt() 函数
- parseFloat() 函数

```js
parseInt("123", 10); // 123
```

## 字面量

在JavaScript中，字面量可以表示值，这些字面量是脚本中按字面意思给出的固定的值，而不是变量

### 数组字面量

数组字面量是由一对方括号`[]`括起来的包含零个或多个表达式的列表,其中每个表达式代表一个数组元素

```js
const coffees = ["French Roast", "Colombian", "Kona"];
```

每次字面量被求值时，数组字面量都会创建一个新的数组对象

#### 数组字面量中的多余逗号

如果你在数组字面量中连续放置两个逗号，数组会为未指定的元素留下一个空槽,末尾的逗号会被忽略。

### 布尔字面量

布尔类型有两种字面量值：true 和 false

### 数字字面量

JavaScript 数字字面量包括多种基数的整数字面量和以 10 为基数的浮点数字面量

值得一提的是，语言规范要求数字字面量必须是无符号的。但是像 -123.4 这样的代码片段还是没有问题的，会被解释为一元操作符 - 应用于数字字面量 123.4。

### 对象字面量

对象字面量是由一对花括号（{}）括起来的包含零个或多个属性名和相关值的列表。

> [!WARNING]
> 你不能在一条语句的开头就使用对象字面量！这将导致错误（或产生超出预料的行为），因为此时 { 会被认为是一个语句块的起始符号

### RegExp字面量

一个正则表达式字面量是字符被正斜杠围成的表达式

```js
const re = /ab+c/;
```

### 字符串字面量

字符串字面量是由一对双引号（"）或单引号（'）括起来的零个或多个字符

#### 模板字面量

模板字面量也可用。模板字面量由一对反引号（`）包围，而不是双引号或单引号
模板字面量为构建字符串提供了语法糖

```js
// 创建基本的字符串字面量
`在 JavaScript 中，“\n” 是换行符。`// 多行字符串
`在 JavaScript 中，模板字符串可以
 跨越行，但是由双引号和单引号
 包裹的字符串不行。`;

// 字符串插值
const name = "Lev",
  time = "today";
`你好 ${name}，${time} 过得怎么样？`;
```
