let x = 5;

if (x > 5) {
	console.log("x is greater than 5");
}

if (x > 5) {
	console.log("x is greater than 5");
} else if (x == 5) {
	console.log("x is equal to 5");
} else {
	console.log("x is less than 5");
}

let fruit = "apple";

switch (fruit) {
	case "banana":
		console.log("I hate bananas");
		beraak;
	case "apple":
		console.log("I love apples");
		break;
	default:
		console.log("I don't know what fruit this is");
}

for (let i = 0; i < 5; i++) {
	console.log(i);
}

let i = 0;
while (i < 5) {
	console.log(i);
	i++;
}

let j = 0;
do {
	console.log(j);
	j++;
} while (j < 5);

let arr = [10, 20, 30];
for (let value of arr) {
	console.log(value); // 输出 10, 20, 30
}

let person = { name: "Alice", age: 25 };
for (let key in person) {
	console.log(key, person[key]); // 输出 name Alice, age 25
}

try {
	let result = 10 / 0; // 这里不会抛出异常，但会返回 Infinity
	console.log(result);
} catch (error) {
	console.log("捕获到错误：", error);
} finally {
	console.log("无论是否发生错误，finally 都会执行");
}
