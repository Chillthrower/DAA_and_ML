import React, { Component, componenet } from 'react';
import DisplayCount from './DisplayCount';
class Counter extends Component
{
    constructor(props)
    {
        super(props);
        this.state = 
        {
            count: 0
        };
    }

    Increment = () => {
        this.setState({count: this.state.count + 1});
    }

    Decrement = () => {
        this.setState({count: this.state.count - 1});
    }

    render() {
        return (
            <div>
                <h2>Count:</h2>
                <button onClick={this.Increment}>Add</button>
                <button onClick={this.Decrement}>Sub</button>
                <p>Count: {this.state.count}</p>
                <DisplayCount count={this.state.count} />
            </div>
        );
    }
}

export default Counter;