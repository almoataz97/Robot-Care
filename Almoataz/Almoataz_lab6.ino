//--exercise 1//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
}
//--exercise 2//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
}
//--exercise 3//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
}
//--exercise 4//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
    }
}
//--exercise 5//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
    }
    Product[] public products;
}
//--exercise 6//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     function _createProduct(string memory _name, uint _id) private {
     Product memory Almoataz = Product(_id, _name);
     products.push(Almoataz);
        }
}
//--exercise 7//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     function _createProduct(string memory _name, uint _id) private {
     Product memory Almoataz = Product(_id, _name);
     products.push(Almoataz);
        }
     function _generateRandomId(string memory _str) private pure returns
(uint) {
}
}
//--exercise 8//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     function _createProduct(string memory _name, uint _id) private {
     Product memory Almoataz = Product(_id, _name);
     products.push(Almoataz);
        }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
}
//--exercise 9//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product({
            name: _name,
            id: _id
        });
        uint productId = products.length;
        products.push(newProduct);
        emit NewProduct(productId, _name, _id);
    }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
}
//--exercise 10//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     mapping (uint => address) public productToOwner;
     mapping (address => uint) public ownerProductCount;
    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product({
            name: _name,
            id: _id
        });
        uint productId = products.length;
        products.push(newProduct);
        emit NewProduct(productId, _name, _id);
    }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
}
//--exercise 11//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     mapping (uint => address) public productToOwner;
     mapping (address => uint) public ownerProductCount;
    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product({
            name: _name,
            id: _id
        });
        uint productId = products.length;
        products.push(newProduct);
        productToOwner[productId] = msg.sender;
        ownerProductCount[msg.sender]++;
        emit NewProduct(productId, _name, _id);
    }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
     function Ownership(uint _productId) public {
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }
}
//--exercise 12//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     mapping (uint => address) public productToOwner;
     mapping (address => uint) public ownerProductCount;
    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product({
            name: _name,
            id: _id
        });
        uint productId = products.length;
        products.push(newProduct);
        productToOwner[productId] = msg.sender;
        ownerProductCount[msg.sender]++;
        emit NewProduct(productId, _name, _id);
    }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
     function Ownership(uint _productId) public {
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }
    
    function getProductsByOwner(address _owner) external view returns (uint[] memory) {
        uint counter = 0;
        uint[] memory result = new uint[](ownerProductCount[_owner]);
        for (uint i = 0; i < products.length; i++) {
            if (productToOwner[i] == _owner) {
                result[counter] = i;
                counter++;
            }
        }
        return result;
    }
}
//--exercise 13//
// contracts/access-control/Auth.sol
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Auth {
    address private _administrator;

    constructor(address deployer) {
        // Make the deployer of the contract the administrator
        _administrator = deployer;
    }

    function isAdministrator(address user) public view returns (bool) {
        return user == _administrator;
    }
}
//--exercise 14//
//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    uint idDigits = 16;
    uint idModulus = 10^idDigits;
    struct Product {
        uint id;
        string name;
     }
     Product[] public products;
     mapping (uint => address) public productToOwner;
     mapping (address => uint) public ownerProductCount;
    event NewProduct(uint indexed ArrayProductId, string name, uint id);

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }

    function _createProduct(string memory _name, uint _id) private {
        Product memory newProduct = Product({
            name: _name,
            id: _id
        });
        uint productId = products.length;
        products.push(newProduct);
        productToOwner[productId] = msg.sender;
        ownerProductCount[msg.sender]++;
        emit NewProduct(productId, _name, _id);
    }
      function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }
     function Ownership(uint _productId) public {
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }
    
    function getProductsByOwner(address _owner) external view returns (uint[] memory) {
        uint counter = 0;
        uint[] memory result = new uint[](ownerProductCount[_owner]);
        for (uint i = 0; i < products.length; i++) {
            if (productToOwner[i] == _owner) {
                result[counter] = i;
                counter++;
            }
        }
        return result;
    }
    modifier olderThan(uint _age, uint _userId) {
        require(_userId >= _age, "User is not old enough");
        _;
    }

    function validationUsers(uint _userId) public view olderThan(18, _userId) {
    }
}
//***************finish**************//