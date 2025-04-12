local str = "Hello, Lua"

print(str:upper())

print(str:lower())

print(str:gsub("Lua", "World"))

print(str:find("lo"))

print(str:reverse())

print(("Hello, %s"):format("World"))

print(str:len())

print("Hello" .. " World")
