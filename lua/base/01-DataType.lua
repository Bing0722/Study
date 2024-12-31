print(type(nil))
print(type(true))
print(type(10.4 * 3))
print(type("Hello world"))
print(type(print))
print(type(type))

local tb1 = {}

print(type(tb1))

local function foo()
	print("Hello")
end

print(type(foo))
