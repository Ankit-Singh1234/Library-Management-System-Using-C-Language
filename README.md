<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management System</title>
    <style>
        @keyframes typing {
            from { width: 0 }
            to { width: 100% }
        }
        @keyframes blink {
            50% { border-color: transparent; }
        }
        .typing-container {
            font-family: monospace;
            font-size: 24px;
            white-space: nowrap;
            overflow: hidden;
            border-right: 3px solid black;
            width: 0;
            animation: typing 3s steps(30, end) forwards, blink 0.75s step-end infinite;
        }
    </style>
</head>
<body>
    <h1 class="typing-container"># Library Management System</h1>
    
    <h2>Overview</h2>
    <p>The <strong>Library Management System (LMS)</strong> is a software solution designed to automate and streamline library tasks...</p>
    
    <h2>Features</h2>
    <h3>1. <strong>Login System</strong></h3>
    <ul>
        <li>Users log in with a username and password.</li>
        <li>Credentials are validated against stored data.</li>
    </ul>
    
    <h3>2. <strong>Main Menu</strong></h3>
    <ul>
        <li>Navigation between <strong>User Module</strong> and <strong>Book Module</strong>.</li>
        <li>Option to exit.</li>
    </ul>
    
    <h3>3. <strong>User Module</strong></h3>
    <ul>
        <li>Register, update, search, delete users.</li>
        <li>Show user list.</li>
    </ul>
    
    <h3>4. <strong>Book Module</strong></h3>
    <ul>
        <li>Add, remove, update books.</li>
        <li>Issue and return books.</li>
        <li>Display issued books.</li>
    </ul>
    
    <h2>Future Enhancements</h2>
    <ul>
        <li>Multi-layer authentication.</li>
        <li>Advanced book search.</li>
        <li>Extended book details.</li>
    </ul>
</body>
</html>
