// Number
let age = 30;
let price = 19.99;
console.log(age, price); // undefined

// String
let names = "John";
let greeting = `Hello ${names}`; // Template literals
let message = `I'm a ${names}`;
console.log(names, greeting, message); // undefined

// boolean
let isAdult = true;
let isSenior = false;
console.log(isAdult, isSenior); // undefined

// undefined
let data;
console.log(data); // undefined

// null
let user = null;
console.log(user); // undefined

// symbol
let sym = Symbol("description");
console.log(sym); // undefined

// BigInt
let bigInt = 1234567890123456789012345678901234567890n;
console.log(bigInt); // undefined

// Object
let person = {
	name: "John",
	age: 30,
	greet: function () {
		console.log("Hello, " + this.name);
	},
};
console.log(person.name); // undefined
person.greet(); // undefined

// Array
let numbers = [1, 2, 3, 4, 5];
let fruits = ["apple", "banana", "cherry"];
console.log(numbers[0], fruits[1]); // undefined

// Function
function add(a, b) {
	return a + b;
}
console.log(add(1, 2)); // undefined

// Date
let now = new Date();
console.log(now); // undefined
