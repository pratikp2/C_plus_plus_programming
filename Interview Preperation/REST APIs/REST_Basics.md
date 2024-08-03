
---
# REST APIs


- REST (Representational State Transfer) is an architectural style for designing networked applications. It relies on a stateless, client-server, cacheable communications protocol -- the HTTP.


## 1. Key Concepts of REST APIs

### 1. Resources and URLs:
Everything in REST is considered a resource. Resources are identified by URLs.
Example: https://api.example.com/users could be the URL for accessing user resources.

### 2. HTTP Methods:
- REST uses standard HTTP methods to perform operations on resources:
  - GET: Retrieve a resource.
  - POST: Create a new resource.
  - PUT: Update an existing resource.
  - DELETE: Delete a resource.
  - PATCH: Partially update a resource.

### 3. Statelessness:

Each request from a client to server must contain all the information the server needs to fulfill that request.
The server cannot store client context between requests.

### 4. Data Formats:

Typically, REST APIs use JSON or XML to exchange data between the client and server. JSON is more common due
to its simplicity and readability.

### 5. Endpoints:

Endpoints are the specific URLs where resources can be accessed. They usually follow a pattern that makes 
the API predictable and easy to use.

#### Example:
- GET /users – Retrieves a list of users.
- GET /users/{id} – Retrieves a specific user by ID.
- POST /users – Creates a new user.
- PUT /users/{id} – Updates a user by ID.
- DELETE /users/{id} – Deletes a user by ID.

<br>


    A REST API body generally consists of data that the client sends to or receives from the server. The structure and components of a REST API body depend on the HTTP method being used (e.g., GET, POST, PUT, DELETE). Below are the typical components of a REST API body:

## 2. Components of a RESTful APIs

### 1. HTTP Method:

- GET: Requests data from a specified resource.
- POST: Submits data to be processed to a specified resource.
- PUT: Updates a specified resource with the provided data.
- DELETE: Deletes the specified resource.

<br>

### 2. Headers:

- Headers provide metadata for the request or response. Common headers include:
- Content-Type: Indicates the media type of the resource (e.g., application/json).
- Authorization: Contains credentials to authenticate a user agent with a server.
- Accept: Informs the server about the types of data that can be sent back (e.g., application/json).
- User-Agent: Provides information about the client making the request.

<br>

### 3. Request Body:

- The request body contains the data sent by the client to the server. It's typically used with POST, PUT, and PATCH methods.
- The body is usually in JSON format but can also be in XML or other formats.
- Example of a JSON request body:
```
json
{
  "id": 1,
  "name": "John Doe",
  "email": "john.doe@example.com"
}
```
<br>

### 4. Response Body:

- The response body contains the data sent by the server to the client. It’s used in response to GET, POST, PUT, and PATCH methods.
- Like the request body, it is usually in JSON format but can also be in XML or other formats.
- Example of a JSON response body:
```
json
{
  "status": "success",
  "data": {
    "id": 1,
    "name": "John Doe",
    "email": "john.doe@example.com"
  }
}
```


### 5. Status Codes:

Status codes indicate the result of the HTTP request. Common status codes include:
- 200 OK: The request was successful.
- 201 Created: The resource was successfully created (typically used with POST).
- 204 No Content: The request was successful, but there is no content to send back.
- 400 Bad Request: The server could not understand the request due to invalid syntax.
- 401 Unauthorized: The client must authenticate itself to get the requested response.
- 404 Not Found: The server can not find the requested resource.
- 500 Internal Server Error: The server has encountered a situation it doesn't know how to handle.
- Example: REST API for a User Resource.

---
<br>

[REST API INTERVIEW QUESTIONS - TURING](https://www.turing.com/interview-questions/rest-api)
<br>

---

