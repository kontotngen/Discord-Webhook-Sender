#pragma once
#include <string>
#include "curl/curl.h"

#ifdef _DEBUG
#pragma comment (lib, "curl/libcurl_a_debug.lib") // libcurl lib
#else
#pragma comment (lib, "curl/libcurl_a.lib") // libcurl lib
#endif

class DWHook {
public:
	  std::string normal = "{\"username\": \"username123\", \"content\": \"text\"}";
    std::string description = "{\"username\": \"username123\", \"content\": null,\"embeds\": [{\"title\": \"descriptiontitle\",\"description\": \"descriptiontext\",\"color\": 4062976}]}";
    void send(std::string content) {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        if (auto* const curl = curl_easy_init())
        {
            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, "Content-Type: application/json");

            curl_easy_setopt(curl, CURLOPT_URL, "WEBHOOK HERE"); // made by ProB!#0100 its simple and easy
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, content.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const CURLcode res = curl_easy_perform(curl);

            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
};
