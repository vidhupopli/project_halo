print("running lua script")
naamJap()

function update()
    local x = getBoxX()
    local y = getBoxY()
    moveBox(x + 1, y + 1)
end