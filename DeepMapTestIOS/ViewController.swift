//
//  ViewController.swift
//  DeepMapTestIOS
//
//  Created by Tan Chung Shzen on 05.09.17.
//  Copyright © 2017 Tan Chung Shzen. All rights reserved.
//

import UIKit
import CoreData
import HDMMapCore
import HDMMapCore.HDMAnnotation

class ViewController: HDMMapViewController, HDMMapViewControllerDelegate {
    
    var coordinate : HDMMapCoordinate?
    var coordinateX : Array<Any> = Array()
    var coordinateY : Array<Any> = Array()
    var coordinateGlobal : Any?
    var ring0 : Array<Any> = Array()
    var rings : Array<Any> = Array()

    //MARK: Properties
    @IBOutlet weak var drawRectButton: UIButton!
    
    
    //MARK: ActionButton
    @IBOutlet weak var confirmButton: UIButton!
   
    @IBAction func drawRect(_ sender: UIButton) {
        //enable user interaction
        
        self.mapView.tapEnabled = true
        self.confirmButton?.isHidden = false
    }
    
    
    @IBAction func confirmFunc(_ sender: UIButton) {
        
        print(coordinateX.count)
        if coordinateX.count == 1 {
            
            print("You've only select one point, please select more than two points")
            coordinateX.removeAll()
            coordinateY.removeAll()
            
            self.mapView.tapEnabled = false
            self.confirmButton?.isHidden = true
            
        } else if coordinateX.count == 2{
            
            //Code for drawing rectangle
            ring0 = [HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[0] as! Double, coordinateY[0] as! Double, 0),crs:""),
                    HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[1] as! Double, coordinateY[0] as! Double, 0), crs:""),
                    HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[1] as! Double, coordinateY[1] as! Double, 0), crs:""),
                    HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[0] as! Double, coordinateY[1] as! Double, 0), crs:""),
                    HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[0] as! Double, coordinateY[0] as! Double, 0),crs:"")]
            
            rings = [ring0]
            
            getBeacon()
            
            coordinateX.removeAll()
            coordinateY.removeAll()

            self.mapView.tapEnabled = false
            self.confirmButton?.isHidden = true
            
        } else if coordinateX.count > 2 {
            
            //Code for drawing polygon
            ring0.removeAll()
            rings.removeAll()
            
            for (x,y) in zip(coordinateX,coordinateY){
                ring0.append((HDMLocation.init(coordinate:HDMMapCoordinateMake(x as! Double, y as! Double, 0),crs:"")))
                }
            
            ring0.append((HDMLocation.init(coordinate:HDMMapCoordinateMake(coordinateX[0] as! Double, coordinateY[0] as! Double, 0),crs:"")))
            rings = [ring0]

            getBeacon()
            
            coordinateX.removeAll()
            coordinateY.removeAll()
            
            self.mapView.tapEnabled = false
            self.confirmButton.isHidden = true

        }
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // set this view as delegate for the hdmmapview
        // this way we receive events for tapAtPoint etc.
        self.mapView.set3DMode(false, animated: false)
        self.delegate = self
        
        //add button to view
        self.view.addSubview(drawRectButton)
        self.view.addSubview(confirmButton)
        
        self.confirmButton?.isHidden = true
        //disable user interaction when draw button is not click
        self.mapView.tapEnabled = false
        }
    
    
    //MARK: Mapview Controls for Rectangle Drawing
    
    func mapViewController(_ controller: HDMMapViewController, tappedAt coordinate: HDMMapCoordinate, features: [HDMFeature]) {

            coordinateGlobal = coordinate
            coordinateX.append(coordinate.x)
            coordinateY.append(coordinate.y)
        
            print(coordinateX.count)
    }
    
    func getBeacon(){
        let alertController = UIAlertController(title: "Beacon Info?", message: "Please enter the information for the Beacon:", preferredStyle: .alert)
        
        let confirmAction = UIAlertAction(title: "Confirm", style: .default) { (_) in
            if let field = alertController.textFields?[0] {
                
                let annotation = HDMAnnotation(coordinate: self.coordinateGlobal as! HDMMapCoordinate)
                annotation.title = "Beacon:" + field.text!
                
                let placeName = alertController.textFields![0] as UITextField
                let beaconName = alertController.textFields![1] as UITextField
                let id = alertController.textFields![2] as UITextField
                let factoryId = alertController.textFields![3] as UITextField
                
                self.mapView.add(annotation)
                self.mapView.createPolygonFeature(self.rings, withType: "markRectangle", zmin: 43, zmax: 44)

            } else {
                // user did not fill field
            }
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel) { (_) in }
        
        alertController.addTextField(configurationHandler: {(textField) -> Void in textField.placeholder = "Place Name" })
        alertController.addTextField(configurationHandler: {(textField) -> Void in textField.placeholder = "Beacon Name" })
        alertController.addTextField(configurationHandler: {(textField) -> Void in textField.placeholder = "Beacon ID" })
        alertController.addTextField(configurationHandler: {(textField) -> Void in textField.placeholder = "Beacon Factory ID" })
        
        alertController.addAction(confirmAction)
        alertController.addAction(cancelAction)
        
        self.present(alertController, animated: true, completion: nil)

    }
}

