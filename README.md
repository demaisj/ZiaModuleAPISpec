# ZiaModuleAPISpec

API specification for "zia" server modules

## So what's the deal with this

Just read the code & comments in `include` for now. More details will come soon.

Also read `src` factory examples.

## Class diagram

```
+---------------------+         +------------------------+         +-----------------+   
| MODULE (class)      |         | SERVER CONFIG (struct) |         | PLATFORM (enum) |   
|                     |         |                        |         |                 |   
| Meta-data:          |         | - name                 |    +----| - Linux         |   
| - getName           |    +----| - version              |    |    | - Windows       |   
|                     |    |    | - platform             -----+    | - Macos         |   
| Hooks:              |    |    | - config               |         +-----------------+   
| - onActivate        |    |    | - apispec_version      -----+                          
| - onDeactivate      |    |    +------------------------+    |    +--------------------+
| - onConfigChange    -----+                                  |    | DEFINITIONS (vars) |
|                     |                                       +----|                    |
| Request handler:    |                                            | - VERSION          |
| - newRequestHandler -----+                                       +--------------------+
+---------------------+    |                                                             
           |               |    +-------------------------+         +------------------+ 
+----------|----------+    |    | REQUEST HANDLER (class) |         | REQUEST (struct) | 
|       FACTORY       |    |    |                         |         |                  | 
+---------------------+    |    | Connection hooks:       |         | - method         | 
                           |    | - onReadRequest         |         | - uri            | 
                           |    | - onWriteResponse       |    +----| - protocol       | 
                           +----|                         |    |    | - headers        | 
                                | Request hooks:          |    |    | - body           | 
                                | - onPreRequest          |    |    | - secure         | 
                                | - onRequest             -----+    +------------------+ 
                                | - onRequestError        -----+                         
                                | - onResponse            |    |    +-------------------+
                                +------------|------------+    |    | RESPONSE (struct) |
                                             |                 |    |                   |
                                +------------------------+     |    | - protocol        |
                                | HOOK RESULT (number)   |     +----| - status_code     |
                                |                        |          | - status_message  |
                                | - Ok                   |          | - headers         |
                                | - Declined             |          | - body            |
                                | - Any HTTP status code |          +-------------------+
                                +------------------------+                               
```
