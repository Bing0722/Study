console.log("\u{1F60D}"); // 😍
console.log("\u00A9");

class Color {
	constructor(r, g, b) {
		// 将 RGB 值作为 `this` 的属性
		this.values = [r, g, b];
	}
}
const red = new Color(255, 0, 0);
console.log(red);
