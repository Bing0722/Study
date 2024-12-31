# 循环与迭代

avaScript 中提供了这些循环语句：

- for 语句
- do...while 语句
- while 语句
- label 语句
- break 语句
- continue 语句
- for...in 语句
- for...of 语句

## for 语句

```js
for ([initialExpression]; [condition]; [incrementExpression]) statement;
```

## do...while 语句

```js
do statement;
while (condition);
```

## while 语句

```js
while (condition) statement;
```

## label 语句

一个 label 提供了一个让你在程序中其他位置引用它的标识符

```js
label: statement;
```

## break 语句

使用 break 语句来终止循环，switch，或者是链接到 label 语句。

```js
break [label];
```

## continue 语句

continue 语句可以用来继续执行（跳过代码块的剩余部分并进入下一循环）一个 while、do-while、for，或者 label 语句。

```js
continue [label];
```

## for...in 语句

for...in 语句循环一个指定的变量来循环一个对象所有可枚举的属性

```js
for (variable in object) {
  statements;
}
```

## for...of 语句

for...of 语句在可迭代对象（包括Array、Map、Set、arguments 等等）上创建了一个循环，对值的每一个独特属性调用一次迭代。

```js
for (variable of object) {
  statement;
}
```

- 区别 for...in 和 for...of
  - for...in 语句以任意顺序遍历一个对象的可枚举属性。
  - for...of 语句遍历可迭代对象定义要迭代的数据。 for

```js
let arr = [3, 5, 7];
arr.foo = "hello";

for (let i in arr) {
  console.log(i); // 输出 "0", "1", "2", "foo"
}

for (let i of arr) {
  console.log(i); // 输出 "3", "5", "7"
}

// 注意 for...of 的输出没有出现 "hello"
```
