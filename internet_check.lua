
local handle = io.popen("./internet_check.exe -v")
local result = handle:read("*a")
print(result)
handle:close()

