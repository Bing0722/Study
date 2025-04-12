-- 初始化表
local tb1 = {}
-- 指定值
tb1[1] = "Lua"
-- 移除引用
tb1 = nil

local tb2 = {}

print("tb2 的类型是 ", type(tb2))

tb2[1] = "Lua"
tb2["wow"] = "this"
print("tb2 索引 1 的元素是 ", tb2[1])
print("tb2 索引 wow 的元素是 ", tb2["wow"])

local tb3 = { "abc", "def", "ghi" }
print(table.concat(tb3, ", "))
print(table.concat(tb3, ", ", 2, 3))

local function printTable(tb)
	for i, v in ipairs(tb) do
		print("index", i, "value", v)
	end
end

printTable(tb3)

table.insert(tb3, 2, "111")

printTable(tb3)

table.remove(tb3, 4)

printTable(tb3)

table.sort(tb3)

printTable(tb3)
