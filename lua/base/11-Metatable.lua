local tb1 = { x = 10, y = 20 }

local mt = {
	__index = function(table, key)
		if key == "z" then
			return 100
		end
	end,
	__add = function(table1, table2)
		return { x = table1.x + table2.x, y = table1.y + table2.y }
	end,
}

setmetatable(tb1, mt)

print(tb1.x) -- 100
