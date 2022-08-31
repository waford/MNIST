//
// Created by waford on 8/29/22.
//

#include "MNISTDataset.hpp"

#include <assert.h>
#include <curl/curl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

MNISTDataset::MNISTDataset(std::string name, std::string imageURL, std::string labelURL):
    datasetName(name),
    imageURL(imageURL),
    labelURL(labelURL),
    directoryPath(kDatasetDirectory + "/" + datasetName)
{   
    init();
}

void MNISTDataset::init() {
    CURL *curl;
    CURLcode res;

    std::string imageFilename = buildFilename(imageURL);
    std::string labelFilename = buildFilename(labelURL);

    touchDatasetDirectory(datasetName);

    curl = curl_easy_init();
    curlURL(curl, imageFilename, imageURL);
    curlURL(curl, labelFilename, labelURL);
    curl_easy_cleanup(curl);
}

void MNISTDataset::curlURL(CURL *curl, std::string filename, std::string url) {
    CURLcode response;
    FILE *dataFile = fopen((directoryPath + "/" + filename).c_str(), "w") ;
    if(curl && dataFile) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) dataFile);

        response = curl_easy_perform(curl);
        assert(response == CURLE_OK);
   }
}

std::string MNISTDataset::buildFilename(std::string url) {
    size_t last_split = url.find_last_of("/");
    size_t penultimate_split;
    if(last_split != url.length() - 1) {
        // Pretend that there is a slash 
        penultimate_split = last_split;
        last_split = url.length();
    } else {
        penultimate_split = url.substr(0, last_split).find_last_of("/");
    }
    return url.substr(penultimate_split + 1, last_split);
}

void MNISTDataset::touchDatasetDirectory(std::string name) {
    // First ensure that the dataests directory exists
    mkdir(kDatasetDirectory.c_str(),  S_IRWXG | S_IRWXU);
    //Then ensure that the specified directory exists
    mkdir((directoryPath).c_str(), S_IRWXG | S_IRWXU);
}
