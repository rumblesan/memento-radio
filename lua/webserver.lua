local app = require("milua")

app.add_handler("GET", "/",
    function()
        return "<h1>Memento Radio!</h1>", {
            ["Content-Type"] = "text/html"
        }
    end
)

app.add_handler("GET", "/health",
    function()
        return "OK", {
            ["Content-Type"] = "text/plain"
        }
    end
)

print(" INFO: [API Server] running at " .. API_HOST .. ":" .. API_PORT)

app.start({
    HOST = API_HOST,
    PORT = API_PORT
})
