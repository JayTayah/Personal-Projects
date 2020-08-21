//
//  ViewController.swift
//  Magic 8 Ball
//
//  Created by Jonathan Tayah on 2019-10-03.
//  Copyright © 2019 Jonathan Tayah. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    let ballArray = ["ball1","ball2","ball3","ball4","ball5"]
    var ballIndex: Int = 0
    
    @IBOutlet weak var ballImage: UIImageView!
   
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        changeBallImage()
    }
    
    @IBAction func askButtonPressed(_ sender: UIButton) {
        
        changeBallImage()
    }
    
    override func motionEnded(_ motion: UIEvent.EventSubtype, with event: UIEvent?) {
        
        changeBallImage()
    }

    func changeBallImage() {
        
        ballIndex = Int.random(in: 0...4)
        ballImage.image = UIImage(named: ballArray[ballIndex])
        
}

}
