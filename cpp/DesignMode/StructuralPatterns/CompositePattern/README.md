# 组合(Composite)

**组合**是一种结构型设计模式，你可以使用它将对象组合成树状结构，并且能像使用独立对象一样使用它们。

## 结构

- **组件**（Component）接口描述了树中简单项目和复杂项目所共有的操作。
- **叶节点**（Leaf）是树的基本结构， 它不包含子项目。
- **容器**（Container）——又名 “组合 （Composite）”——是包含叶节点或其他容器等子项目的单位。 容器不知道其子项目所属的具体类， 它只通过通用的组件接口与其子项目交互。
- **客户端**（Client）通过组件接口与所有项目交互。 因此， 客户端能以相同方式与树状结构中的简单或复杂项目交互。

## 使用场景

- 如果你需要实现树状对象结构， 可以使用组合模式。
- 如果你希望客户端代码以相同方式处理简单和复杂元素， 可以使用该模式。

## 实现方式

- 确保应用的核心模型能够以树状结构表示。 尝试将其分解为简单元素和容器。 记住， 容器必须能够同时包含简单元素和其他容器。
- 声明组件接口及其一系列方法， 这些方法对简单和复杂元素都有意义。
- 创建一个叶节点类表示简单元素。 程序中可以有多个不同的叶节点类。
- 创建一个容器类表示复杂元素。 在该类中， 创建一个数组成员变量来存储对于其子元素的引用。 该数组必须能够同时保存叶节点和容器， 因此请确保将其声明为组合接口类型。
- 最后， 在容器中定义添加和删除子元素的方法。

## 优缺点

**优点**：

- 你可以利用多态和递归机制更方便地使用复杂树结构。
- 开闭原则。 无需更改现有代码， 你就可以在应用中添加新元素， 使其成为对象树的一部分。

**缺点**：

- 对于功能差异较大的类， 提供公共接口或许会有困难。 在特定情况下， 你需要过度一般化组件接口， 使其变得令人难以理解。

> 核心思想: