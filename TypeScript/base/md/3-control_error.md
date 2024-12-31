# 流程控制与错误处理

## 块语句

最基本的语句是用于组合语句的块语句。块由一对花括号界定：

```js
{
  statement1;
  statement2;
  // …
  statementN;
}
```

## 条件语句

### if...else 语句

使用 if 语句在逻辑条件为 true 时执行语句。使用可选的 else 子句在条件为 false 时执行语句。

```js
if (condition) {
  statement1;
} else {
  statement2;
}
```

> [!Tip]
> 这些指为假值： false, 0, "", null, undefined, NaN假值

### switch 语句

switch 语句允许程序求一个表达式的值并且尝试将表达式的值和 case 标签进行匹配。如果匹配成功，程序会执行相关的语句。

```js
switch (expression) {
  case label1:
    statements1;
    break;
  case label2:
    statements2;
    break;
  // …
  default:
    statementsDefault;
}
```

### break 语句

每个 case 子句会关联一个可选的 break 语句，它能保证在匹配的语句被执行后程序可以跳出 switch 并且继续执行 switch 后面的语句

## 异常处理语句

你可以用 throw 语句抛出一个异常并且用 try...catch 语句处理它。

### 异常类型

JavaScript 可以抛出任意对象。然而，并非所有抛出的对象都是生而平等的。
尽管抛出数字或者字符串作为错误信息十分常见，但是用下列其中一种专门为这个目的而创建的异常类型通常更为高效：

- ECMAScript 标准异常类型
- DOMException

### throw 语句

你可以抛出任意表达式而不是特定类型的表达式:

```js
throw "错误 2"; // 字符串类型
throw 42; // 数字类型
throw true; // 布尔类型
throw {
  toString() {
    return "我是一个对象";
  },
};
```

### try...catch 语句

try...catch 语句用于标记一段要尝试的语句块，并指定抛出异常时的一个或多个响应。
如果抛出了异常，try...catch 语句会捕获它。

### catch 块

你可以使用 catch 块来处理所有可能在 try 块中产生的异常。

### finally 块

finally 块包含的语句在 try 和 catch 块执行之后执行。此外，finally 块在 try…catch…finally 语句后面的代码之前执行。

也应该注意，finally 块无论是否抛出异常都会执行。如果抛出了一个异常，就算没有 catch 块处理抛出的异常，finally 块里的语句也会执行。

```js
openMyFile();
try {
  writeMyFile(theData); // 这可能会抛出错误
} catch (e) {
  handleError(e); // 如果错误出现了，处理它
} finally {
  closeMyFile(); // 总是关闭资源
}
```
