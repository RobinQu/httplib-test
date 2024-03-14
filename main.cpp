#include <iostream>
#include <httplib.h>


using namespace httplib;

static void send_request(Client& client, const std::string& body) {
    auto res = client.Post("/api/chat", body, "application/json");
    if (res) {
        std::cout << res->body << std::endl;
    } else {
        std::cout << to_string(res.error()) << std::endl;
    }
}

int main()
{
    Client client {"http://localhost:11434"};
    std::string request_body_1 = R"({
        "model": "llama2",
        "messages": [
            {
                "role": "user",
                "content": "why is the sky blue?"
            }
        ],
        "stream": false
    })";

    // request_body_1 is okay
    send_request(client, request_body_1);


    std::string request_body_2 = R"({"model":"llama2:latest","messages":[{"role":"user","content":"Summarize the following document:\n\n# Quick and Easy Chicken Spaghetti\n\nSource: https://www.allrecipes.com/recipe/26286/quick-and-easy-chicken-spaghetti/?print\n\nThis chicken spaghetti recipe is quick and easy to make, yet is hearty and delicious. It's a great way to use leftover chicken!\n\n\nPrep Time: 10 mins\nCook Time: 15 mins\nTotal Time: 25 mins\nServings: 6\n\n\n## Ingredients\n1 (12 ounce) package angel hair pasta\n\n2 cups chopped cooked chicken breast\n\n1 (10.75 ounce) can condensed cream of chicken soup\n\n1 (10 ounce) can diced tomatoes with green chile peppers\n\n¾ (8 ounce) package processed cheese, cubed\n\n½ (4 ounce) jar sliced mushrooms, drained\n\nsalt and pepper to taste\n\n## Directions\nBring a large pot of lightly salted water to a boil. Cook angel hair pasta in the boiling water, stirring occasionally, until tender yet firm to the bite, 4 to 5 minutes. Drain pasta and return it to the pot.\n\nAdd chopped chicken, condensed soup, diced tomatoes with chile peppers, processed cheese, mushrooms, salt, and pepper.\n\nCook and stir over low heat until cheese is melted and mixture is heated through, about 5 minutes.\n\n"}],"stream":false,"format":"json","options":{"temperature":0}})";
    // request_body_2 is okay
    send_request(client, request_body_2);

    return 0;
}
