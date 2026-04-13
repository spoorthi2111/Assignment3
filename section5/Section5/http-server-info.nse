description = [[
Gets HTTP server info
]]

author = "Student"

portrule = function(host, port)
    return port.number == 80 or port.number == 8080
end

action = function(host, port)
    return "Server info script executed"
end