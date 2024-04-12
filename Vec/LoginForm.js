import React, {Component} from 'react';

class LoginForm extends Component
{
    constructor(props)
    {
        super(props);
        this.state = 
        {
            username: '',
            password: '',
            submitted: false
        };
    }

    handleInputChange = (event) => {
        const {name, value} = event.target;
        this.setState({[name]: value});
    }

    handleSubmit = (event) => {
        event.preventDefault();
        const {username, password} = this.state;
        console.log("Submitted Username:", username);
        console.log("Submitted Password:", password);
        this.setState({submitted: true});
    }

    render() {
        const {username, password, submitted} = this.state;
        return (
            <div>
                <h2>LoginForm</h2>
                <form onSubmit={this.handleSubmit}>
                    <div>
                        <label>Username:</label>
                        <input 
                            type='text'
                            name='username'
                            value={username}
                            onChange={this.handleInputChange}
                            required
                        />
                    </div>
                    <div>
                        <label>Password:</label>
                        <input 
                            type='password'
                            name='password'
                            value={password}
                            onChange={this.handleInputChange}
                            required
                        />
                    </div>
                    <button type='submit'>Click Me</button>
                </form>
                {submitted && <p>Success</p>}
            </div>
        );
    }
}

export default LoginForm;