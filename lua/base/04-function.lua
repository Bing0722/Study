local function max(num1, num2)
	local result
	if num1 > num2 then
		result = num1
	else
		result = num2
	end
	return result
end

print("The max number is: ", max(10, 4))

local function average(...)
	local result = 0
	local arg = { ... }
	for i, v in ipairs(arg) do
		result = result + v
	end
	print("total arguments: ", #arg)
	return result / #arg
end

print("The average is: ", average(10, 4, 12, 5, 6))
